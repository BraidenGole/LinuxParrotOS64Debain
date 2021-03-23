"""
    [DESCRIPTION]: Python 3, playing around with the os, sys module(s), and linux related availability.
"""
import os
import sys

class System:
    """
    Name        :   System
    Purpose     :   This class will have methods that relate to handling
                    the system.
    """

    _read_mode = 'r'
    _write_mode = 'w'

    def concurrent_process(self, read_me, write_me):
        process_id = os.fork()
        if process_id > 0:
            # Close the write end of the pipe becuase we are not using.
            os.close(write_me)
            try:
                with os.fdopen(read_me, self._read_mode) as read_from_pipe:
                    content = read_from_pipe.read()
                    print()
                    print("-----------------------------------------------------------------------"
                          + "-----------------------------------------------------------------------------------------")
                    print(content)
                    print("-----------------------------------------------------------------------"
                          + "-----------------------------------------------------------------------------------------")
            except PermissionError:
                print("You do not have permission to read from this file.")
            except BrokenPipeError:
                print("Pipe is broken !")   
        else:
            # Close the read end of the pipe because we are not using.
            os.close(read_me)
            try:
                with os.fdopen(write_me, self._write_mode) as write_to_pipe:
                    write_to_pipe.write("Pid: " + str(os.getpid()) + "\n")
                    write_to_pipe.write("Operating System: " + os.name + "\n")
                    write_to_pipe.write("File name of controlling terminal process: " + os.ctermid() + "\n")
                    write_to_pipe.write("Login name: " + os.getlogin() + "\n")
                    write_to_pipe.write("\n")
                    write_to_pipe.write("CPU count: " + str(os.cpu_count()) + "\n")
                    write_to_pipe.write(str(os.uname()) + "\n")
            except PermissionError:
                print("You do not have permission to write to this file.")
    
    def close_on_exec(self):
        read_me, write_me = os.pipe2(os.O_CLOEXEC)

        processId = os.fork()
        if processId > 0:
            os.close(write_me)
            try:
                with os.fdopen(read_me, self._read_mode) as read_from_pipe:
                    content = read_from_pipe.read()
                    print()
                    print(content)
            except PermissionError:
                print("You do not have permission to read from this file.")
            except BrokenPipeError:
                print("Pipe is broken !")
        else:
            os.close(read_me)
            try:
                with os.fdopen(write_me, self._write_mode) as write_to_pipe:
                    write_to_pipe.write("Login name: " + os.getlogin() + "\n")
                    write_to_pipe.write("Pid: " + str(os.getpid()) + "\n")
                    write_to_pipe.write("Platform: " + sys.platform + "\n")
                    write_to_pipe.write("System ID: " + str(os.getsid(processId)) + "\n")
                    write_to_pipe.write("API version: " + str(sys.api_version) + "\n")
                    write_to_pipe.write("System version: " + sys.version + "\n")
            except PermissionError:
                print("You do not have permission to write to this file.")
            
    
if __name__ == "__main__":

    sysHandle = System()

    # Create the pipe.
    read_end, write_end = os.pipe()

    sysHandle.concurrent_process(read_end, write_end)
    sysHandle.close_on_exec()
