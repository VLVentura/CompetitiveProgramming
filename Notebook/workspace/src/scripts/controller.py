from src.scripts.system import System
from src.scripts.test import Test


class ScriptsController:
    _call = {
        'compile': System.compile,
        'run': System.run,
        'make_files': System.make_files,
        'remove_files': System.remove_files,
        'save': System.save_file,
        'copy': System.save_file,
        'test_in': Test.test_in,
        'test_out': Test.test_out,
        'test_cases': Test.test_cases,
        'compare': Test.compare
    }

    @staticmethod
    def execute(function: str, args):
        if args is None:
            ScriptsController._call[function]()
        else:
            ScriptsController._call[function](args)
