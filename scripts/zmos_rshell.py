import subprocess
import code
import readline
from rlcompleter import Completer


def _run_cmd(cmd):
    try:
        result = subprocess.run(cmd, shell=True, check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, encoding='utf-8')
        if result.returncode == 0:
            return result.stdout.strip()
        else:
            print('Error:', result.stderr.strip())
            return None
    except subprocess.CalledProcessError as e:
        print('Error:', e.stderr.strip())
        return None


def ls(path):
    # TODO: add generic RPC call with MOS query builder
    cmd = f'mos --port http://127.0.0.1:8080/rpc call FS.List \'{{"path": "{path}"}}\''
    # mos --port http://127.0.0.1:8080/rpc call FS.Get "{\"filename\": \"$1\"}"
    print('Executing', cmd)
    return _run_cmd(cmd)


def cat():
    pass


def rpc_call():
    pass


def rpc_list():
    pass


readline.set_completer(Completer().complete)
readline.parse_and_bind("tab: complete")
code.interact(local=locals())
