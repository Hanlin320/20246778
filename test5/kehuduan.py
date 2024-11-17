import socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server_address = ('localhost', 8888)

client_socket.connect(server_address)

message = 'xiebianshi:'

client_socket.send(message.encode())

data = client_socket.recv(1024)

print()

client_socket.close()