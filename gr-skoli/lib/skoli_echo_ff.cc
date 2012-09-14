/* -*- c++ -*- */
/* 
 * Copyright 2012 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gr_io_signature.h>
#include <skoli_echo_ff.h>


skoli_echo_ff_sptr
skoli_make_echo_ff (unsigned int sample_rate, float delay, float echo_scaling)
{
	return skoli_echo_ff_sptr (new skoli_echo_ff (sample_rate, delay, echo_scaling));
}

// specify constraints on num of input and output streams
static const int MIN_IN = 1; 
static const int MAX_IN = 1; 
static const int MIN_OUT = 1; 
static const int MAX_OUT = 1; 

skoli_echo_ff::skoli_echo_ff (unsigned int sample_rate, float delay, float echo_scaling)
	: gr_block ("echo_ff",
		gr_make_io_signature (MIN_IN, MAX_IN, sizeof (float)),
		gr_make_io_signature (MIN_IN, MAX_IN, sizeof (float)))
{
	d_sample_rate = sample_rate;
	d_delay = delay;
	d_echo_scaling = echo_scaling;
	d_delay_samples = (unsigned int)(d_sample_rate * d_delay);
	d_delay_samples = d_delay_samples? d_delay_samples:1;
	set_history(d_delay_samples);
}


skoli_echo_ff::~skoli_echo_ff ()
{
}


int
skoli_echo_ff::general_work (int noutput_items,
			       gr_vector_int &ninput_items,
			       gr_vector_const_void_star &input_items,
			       gr_vector_void_star &output_items)
{
  const float *in = (const float *) input_items[0];
  float *out = (float *) output_items[0];

	for (int i = 0; i<noutput_items; i++)
	{
		out[i]=d_echo_scaling*in[i]+in[i+d_delay_samples];
	}	
  // Tell runtime system how many input items we consumed on
  // each input stream.
  consume_each (noutput_items);

  // Tell runtime system how many output items we produced.
  return noutput_items;
}

