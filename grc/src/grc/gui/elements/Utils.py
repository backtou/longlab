"""
Copyright 2008 Free Software Foundation, Inc.
This file is part of GNU Radio

GNU Radio Companion is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

GNU Radio Companion is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
"""
##@package grc.gui.elements.Utils
#Shared functions for flow graph elements.
#@author Josh Blum

def get_angle_from_coordinates((x1,y1), (x2,y2)):
	"""!
	Given two points, calculate the vector direction from point1 to point2, directions are multiples of 90 degrees.
	@param (x1,y1) the coordinate of point 1
	@param (x2,y2) the coordinate of point 2
	@return the direction in degrees
	"""
	if y1 == y2:#0 or 180		
		if x2 > x1: return 0
		else: return 180		
	else:#90 or 270
		if y2 > y1: return 270
		else: return 90

def xml_encode(string):
	"""
	Encode a string into an xml safe string by replacing special characters.
	@param string the input string
	@return output string with safe characters
	"""
	string = str(string)
	for char, safe in (
			('&', '&amp;'),
			('<', '&lt;'),
			('>', '&gt;'),
			('"', '&quot;'),
			("'", '&apos;'),
	): string = string.replace(char, safe)
	return string
