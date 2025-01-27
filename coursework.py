import socket

target = input("Enter the target (IP or hostname): ")
start_port = int(input("Enter the start port: "))
end_port = int(input("Enter the end port: "))

print(f"Scanning target: {target} from port {start_port} to {end_port}")

for port in range(start_port, end_port + 1):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.settimeout(0.5)
    result = s.connect_ex((target, port))
    if result == 0:
        print(f"Port {port} is OPEN")
    else:
        print(f"Port {port} is CLOSED")
    s.close()
