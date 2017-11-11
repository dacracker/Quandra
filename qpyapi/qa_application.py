from .qa_dynlib import _qa_bind
from ctypes import c_int32

qapp_init = _qa_bind('qapp_init', None, c_int32)
qapp_quit = _qa_bind('qapp_quit')
