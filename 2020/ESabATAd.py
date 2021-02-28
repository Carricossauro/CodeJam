# I can't believe I'm actually doing this ffs
# Python solved my IO problems but now it only passes the first test
# Idk what's wrong, it works when tested manually
# Didn't coment the code because there is no more patience left
import sys

def getNextNumbers(k, B):
    print(k+1, flush=True)

    inp = input()
    if inp == "N":
        sys.exit()
    else:
        num1 = int(inp)

    print(B-k, flush=True)

    inp = input()
    if inp == "N":
        sys.exit()
    else:
        num2 = int(inp)

    return (num1, num2)

def getNumber(k):
    print(k+1, flush=True)

    inp = input()
    if inp == "N":
        sys.exit()
    else:
        num = int(inp)

    return num

def fixComplementation(array):
    array = [(x + 1) % 2 for x in array]
    return array

def fixReversal(array):
    return array[::-1]

def storeNumbers(array, num1, num2, k, B):
    array[k] = num1
    array[B-k-1] = num2
    return array

def fixArray(array, complementation, reversal):
    if complementation:
        array = fixComplementation(array)
    if reversal:
        array = fixReversal(array)
    return array

def main():
    [T, B] = list(map(int,input().split()))
    for _ in range(T):
        array = [0] * B
        k = 0
        total = 2
        samePairk = diffPairk = -1
        queries = 2
        comp = rev = False

        nums = getNextNumbers(0, B)
        storeNumbers(array, nums[0], nums[1], k, B)
        k+=1

        if nums[0] == nums[1]:
            samePairk = k-1
        elif nums[0] != nums[1]:
            diffPairk = k-1

        while total < B:
            while queries % 10 != 0:
                nums = getNextNumbers(k, B)
                array = storeNumbers(array, nums[0], nums[1], k, B)
                k += 1
                queries += 2
                
                if samePairk == -1 and nums[0] == nums[1]:
                    samePairk = k-1
                elif diffPairk == -1 and nums[0] != nums[1]:
                    diffPairk = k-1
                
                total += 2
                if total >= B:
                    break
            
            comp = rev = False
            if total < B:
                if samePairk != -1:
                    num = getNumber(samePairk)
                    queries += 1
                    if array[samePairk] != num:
                        comp = True
                if diffPairk != -1:
                    num = getNumber(diffPairk)
                    queries += 1
                    if array[diffPairk] != num:
                        if not comp:
                            rev = True
                    elif comp:
                        rev = True
            array = fixArray(array, comp, rev)

        print("".join([str(x) for x in array]), flush=True)
        result = input()
        if result == "N":
            return -1
    return 0

main()