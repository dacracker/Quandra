from .qa_dynlib import _qa_bind
from ctypes import c_int32

QApp_Init = _qa_bind('QApp_Init', None, c_int32)
QApp_Quit = _qa_bind('QApp_Quit')
QApp_Sleep = _qa_bind('QApp_Sleep', [c_int32])
