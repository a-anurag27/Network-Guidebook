import math 
#To find mask
def Mask(mask):
    L=[]
    for i in range(mask):
        L.append(1)
    for i in range(32-mask):
        L.append(0)
    return L
    
#To calculate Binary value from Decimal
def Binary(n):
    d=0
    diff=0
    BinNum=[]
    while(n>0):
        d=n%2
        n=n//2
        BinNum.append(d)
    if(len(BinNum)!=8):
        diff=8-len(BinNum)
        for i in range(diff):
            BinNum.append(0)   
    BinNum.reverse()
    return BinNum
    
#Display Function
def Display(L):
    for i in range(len(L)-1):
        print(str(L[i])+".",end="")
    print(str(L[i+1]))
    
#Converting Back to Decimal
def Decimal(binary):
    i=7
    sumb=0
    for bit in binary:
       sumb=sumb+bit*2**i
       i=i-1
    return sumb
    
#Taking Input
ip=input("Enter IP Address with mask : ")
ip,mask=ip.split('/')
mask=int(mask)
if(mask>32 or mask<0):
    print("Invalid Mask!")
else:
        ip=ip.split('.')
        for i in range(0,len(ip)):
                       ip[i]=int(ip[i])
        ipBin = []
        for value in ip:
            ret=Binary(value)
            for each in ret:
                ipBin.append(each)
        s=0
        maskBin=[]
        for i in range(mask):
            maskBin.append(1)
        for i in range(len(maskBin),32):
            maskBin.append(0)  
        for i in range(24,32):
            if(maskBin[i]==1):
                s+=1
        print("The number of subnets are: " + str(int(math.pow(2,s))))
        MaskBin=Mask(mask)
        Firstadr=[]
        for i in range(len(MaskBin)):
            Firstadr.append(MaskBin[i] and ipBin[i])
        FirstadrD=[]
        for i in range(4):
            FirstadrD.append(Decimal(Firstadr[i*8:8*(i+1)]))
        print("The number of addresses are: " + str(2**(32-mask)))
        print("The First Address is: ")
        Display(FirstadrD)
        Lastadr=[]
        for i in range(len(MaskBin)):
            Lastadr.append(ipBin[i] or int(not MaskBin[i]))
        LastadrD=[]
        for i in range(4):
            LastadrD.append(Decimal(Lastadr[i*8:8*(i+1)]))
        print("\nThe Last Address is:")
        Display(LastadrD)
