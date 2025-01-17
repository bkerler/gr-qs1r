/* -*- c++ -*- */
/* 
 * Copyright 2016 <+YOU OR YOUR COMPANY+>.
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

#ifndef INCLUDED_QS1R_QS1R_SRC_IMPL_H
#define INCLUDED_QS1R_QS1R_SRC_IMPL_H

#include <gnuradio/qs1r/qs1r_src.h>

namespace gr {
  namespace qs1r {

    class qs1r_src_impl : public qs1r_src
    {
     private:
      // Nothing to declare in this block.

     public:
      qs1r_src_impl(unsigned long frequency, unsigned int samplerate, bool pga_flag, bool rand_flag, bool dith_flag, int ppm);
      ~qs1r_src_impl();

      // Where all the action really happens
      int work(int noutput_items,
	       gr_vector_const_void_star &input_items,
	       gr_vector_void_star &output_items);
    };

  } // namespace qs1r
} // namespace gr

#endif /* INCLUDED_QS1R_QS1R_SRC_IMPL_H */

