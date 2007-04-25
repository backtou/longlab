/* -*- c++ -*- */
/*
 * Copyright 2007 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */
#ifndef INCLUDED_MB_RUNTIME_THREAD_PER_MBLOCK_H
#define INCLUDED_MB_RUNTIME_THREAD_PER_MBLOCK_H

#include <mb_runtime.h>

/*!
 * \brief Concrete runtime that uses a single thread for all work.
 */
class mb_runtime_thread_per_mblock : public mb_runtime
{
  mb_mblock_sptr	d_top;		// top mblock

public:
  mb_runtime_thread_per_mblock();
  ~mb_runtime_thread_per_mblock();

  bool run(mb_mblock_sptr top);
};

#endif /* INCLUDED_MB_RUNTIME_THREAD_PER_MBLOCK_H */