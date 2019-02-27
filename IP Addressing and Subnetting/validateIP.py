ip= input("Enter IP Address (Dotted Decimal Form): \n")
ip=ip.split('.')
f=0
for i in ip:
    if(i.isdigit()==False):
        f=1
#print(ip)
if(len(ip)!=4):
    f=1

for each in ip:
    if each[0]=='0'and len(each)!=1:
        f=1
        break
if(f!=1):
    for i in range(0,len(ip)): 
        ip[i]=int(ip[i])
        
    for each in ip:
        if(each>255 and each<0):
            f=1
            break
    
if(f==0):
    print("IP address is Valid!")
else:
    print("IP Address is Invalid!")
