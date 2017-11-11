from .qa_dynlib import _qa_bind
from ctypes import c_char_p, POINTER, c_void_p

va_list = c_void_p
va_list_p = POINTER(va_list)

_qa_printf = _qa_bind('qa_printf', [c_char_p], None)


def qa_printf(frmt):
	print(frmt)
   # _qa_printf(frmt.encode('UTF-8'))
