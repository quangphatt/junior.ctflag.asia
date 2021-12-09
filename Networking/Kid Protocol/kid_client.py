#!/usr/bin/python3
import socket
import json
import struct

# Chuyển phần data về định dạng của Packet
def parse(body):
        data = json.dumps(body).encode()
        length = len(data)
        content_length = struct.pack("<H", length)
        return content_length + data

def main():
    # UDP
    s = socket.socket(family=socket.AF_INET, type=socket.SOCK_DGRAM)
    s.connect(("178.128.19.56", 3108))   

    # phần body của packet
    body = {"action": "read", "file": "flag.txt"}

    packet = parse(body)
    # Gửi packet lên Server
    s.send(packet)
    # Nhận lại phản hồi từ Server
    print(s.recvfrom(4096))

main()