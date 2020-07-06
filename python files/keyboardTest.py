import pyHook, pythoncom

key = ''

def OnKeyboardEvent(event): 
    key = event.Key
    if key == 'Up':
        print("up")
    if key == 'Left':
        print("left")
    if key == 'Down':
        print("down")
    if key == 'Right':
        print("right")

    return True

# When the user presses a key down anywhere on their system 
# the hook manager will call OnKeyboardEvent function.     
hm = pyHook.HookManager()
hm.KeyDown = OnKeyboardEvent
hm.HookKeyboard()

while True:
    pythoncom.PumpWaitingMessages()
