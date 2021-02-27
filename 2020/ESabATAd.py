# I can't believe I'm actually doing this ffs
import sys

def getNextNumbers(k, B):
    print(k+1, flush=True) # Give position to get

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

def fixArray(array, complementation, reversal):
    if complementation:
        array = fixComplementation(array)
    if reversal:
        array = fixReversal(array)
    return array

def main():
    [T, B] = list(map(int,input().split()))
    array = [0] * B
    for x in range(T):
        k = 0
        total = 2
        samePairk = diffPairk = -1
        queries = 2
        comp = rev = False

        nums = getNextNumbers(k, B)
        storeNumbers(array, nums[0], nums[1], k, B)
        k+=1

        if samePairk == -1 and nums[0] == nums[1]:
            samePairk = k-1
        elif diffPairk == -1 and nums[0] == nums[1]:
            diffPairk = k-1

        while total < B:
            while queries % 10 != 0:
                nums = getNextNumbers(k, B)
                storeNumbers(array, nums[0], nums[1], k, B)
                k += 1
                queries += 2
                
                if samePairk == -1 and nums[0] == nums[1]:
                    samePairk = k-1
                elif diffPairk == -1 and nums[0] == nums[1]:
                    diffPairk = k-1
                
                total += 2
                if total >= B:
                    break
            
            if total < B:
                comp = rev = False
                if samePairk != 0:
                    num = getNumber(samePairk)
                    queries += 1
                    if array[samePairk] != num:
                        comp = True
                if diffPairk != 0:
                    num = getNumber(diffPairk)
                    queries += 1
                    if array[diffPairk] != num:
                        if not comp:
                            rev = True
                    elif comp:
                        rev = True
            fixArray(array, comp, rev)

        print("".join([str(x) for x in array]), flush=True)
        result = input()
        if result == "N" or result != "Y":
            return -1
    return 0

main()