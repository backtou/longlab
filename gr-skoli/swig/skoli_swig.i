/* -*- c++ -*- */

#define SKOLI_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "skoli_swig_doc.i"


%{
#include "skoli_echo_ff.h"
%}


GR_SWIG_BLOCK_MAGIC(skoli,echo_ff);
skoli_echo_ff_sptr skoli_make_echo_ff( unsigned int sample_rate, float delay, float echo_scaling);

class skoli_echo_ff : public gr_block
{
        private:
        skoli_echo_ff (unsigned int sample_rate, float delay, float echo_scaling);
};
%include "skoli_echo_ff.h"
