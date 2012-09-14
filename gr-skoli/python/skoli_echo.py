#!/usr/bin/python
import skoli
from gnuradio import gr
from gnuradio import audio
from gnuradio.eng_option import eng_option
from optparse import OptionParser

class skoli_echo(gr.top_block):

	def __init__(self):
		gr.top_block.__init__(self)

		parser = OptionParser(option_class=eng_option)
		parser.add_option("-I","--audio-input",type="string", default="",
		help="pcm input device name. E.g., hw:0.0 or /dev/dsp")
		parser.add_option("-O","--audio-output",type="string", default="",
		help="pcm output device name. E.g., hw:0,0 or /dev/dsp")
		parser.add_option("-r","--sample-rate",type="eng_float",default=48000,
		help="set sample rate to RATE(48000")
		parser.add_option("-D","--echo-delay", type="eng_float", default="0.5", 
		help="Echo delay in seconds. E.g., 0.5")
		parser.add_option("-A","--echo-scaling",type="eng_float", default="0.5",
		help="Amplitude Scaling for echo samples, E.g., 0.3") 
	
		(options, args)=parser.parse_args()
		if len(args) != 0:
			parser.print_help()
			raise SystemExit, 1
		
		sample_rate = int(options.sample_rate)
		src = audio.source(sample_rate, options.audio_input)
		dst = audio.sink(sample_rate, options.audio_output)
		echo = skoli.echo_ff(options.sample_rate, options.echo_delay, options.echo_scaling)
		
		self.connect(src, echo, dst)

if __name__=='__main__':
	try:
		skoli_echo().run()
	except KeyboardInterrupt:
		pass
		
