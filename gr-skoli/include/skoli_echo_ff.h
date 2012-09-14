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

#ifndef INCLUDED_SKOLI_ECHO_FF_H
#define INCLUDED_SKOLI_ECHO_FF_H

#include <skoli_api.h>
#include <gr_block.h>

class skoli_echo_ff;
typedef boost::shared_ptr<skoli_echo_ff> skoli_echo_ff_sptr;

SKOLI_API skoli_echo_ff_sptr skoli_make_echo_ff (unsigned int sample_rate, float delay, float echo_scaling);

/*!
 * \brief <+description+>
 *
 */
class SKOLI_API skoli_echo_ff : public gr_block
{
private:
	friend SKOLI_API skoli_echo_ff_sptr skoli_make_echo_ff (unsigned int sample_rate, float delay, float echo_scaling);

	skoli_echo_ff (unsigned int sample_rate, float delay, float echo_scaling);
//internal members
	unsigned int d_sample_rate;
	float d_delay;
	float d_echo_scaling;
	unsigned int d_delay_samples;

 public:
	~skoli_echo_ff ();


  int general_work (int noutput_items,
		    gr_vector_int &ninput_items,
		    gr_vector_const_void_star &input_items,
		    gr_vector_void_star &output_items);
};

#endif /* INCLUDED_SKOLI_ECHO_FF_H */

