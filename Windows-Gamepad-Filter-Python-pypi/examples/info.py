from windows_gamepad_filter import Client
with Client() as client:
    print(client.info())
