from ctypes import *
from ctypes.util import *


_qlibname = 'quandra'
_qlibpath = find_library(_qlibname)

if _qlibpath is None:
    _qlibpath = find_library(_qlibname + 'd')

    if _qlibpath is None:
        print('FATAL ERROR: Failed to find the quena game engine')
        exit(1)
    else:
        print('Found the Quandra Game Engine, debug version')
else:
    print('Found the Quandra Game Engine, release version')

_qandralib = CDLL(_qlibpath)


def _qa_bind(funcname, args=None, returns=None):
    func = getattr(_qandralib, funcname, None)

    if not func:
        print('_qa_bind: Failed to bind function: ' + funcname)
        return None

    func.argtypes = args
    func.restype = returns

    return func
