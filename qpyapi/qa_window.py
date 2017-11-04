from .qa_dynlib import _qa_bind
from ctypes import c_int32, c_char_p, c_void_p

_QWindow_Create = _qa_bind('QWindow_Create',
                           [c_char_p, c_int32, c_int32], c_void_p)
_QWindow_Destroy = _qa_bind('QWindow_Destroy', [c_void_p])
_QWindow_Show = _qa_bind('QWindow_Show', [c_void_p])
_QWindow_Hide = _qa_bind('QWindow_Hide', [c_void_p])
_QWindow_PumpEvents = _qa_bind('QWindow_PumpEvents', [c_void_p])


class QWindow:
    def __init__(self, title, width, height):
        self.window = _QWindow_Create(title.encode('utf-8'), width, height)

    def show(self):
        _QWindow_Show(self.window)

    def hide(self):
        _QWindow_Hide(self.window)

    def pump_events(self):
        _QWindow_PumpEvents(self.window)

    def destroy(self):
        _QWindow_Destroy(self.window)
