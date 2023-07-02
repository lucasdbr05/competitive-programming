while True:
    enter = input()
    hex_dict = {
        0:"0",1:"1",2:"2",3:"3",4:"4",5:"5",6:"6",7:"7",8:"8",9:"9",10:"A",11:"B",12:"C",13:"D",14:"E",15:"F",
    }
    if enter[0] == "-": break
    if enter[0:2]== "0x":
        ans = int(enter, 16)
    else:
        num = int(enter)
        ans = ""
        while num>16:
            d = num % 16
            num //=16
            ans= hex_dict[d] + ans
        ans = "0x"+ hex_dict[num] + ans
    print(ans)

"""
enter = input()
hex_dict = {
    0:"0",1:"1",2:"2",3:"3",4:"4",5:"5",6:"6",7:"7",8:"8",9:"9",10:"A",11:"B",12:"C",13:"D",14:"E",15:"F",
}

ans = ""
if enter[0:2]== "0x":
    ans = int(enter, 16)
else:
    num = int(enter)
    while num>16:
        d = num % 16
        num //=16
        ans= hex_dict[d] + ans
    ans = "0x"+hex_dict[num] + ans

print(ans)
"""

