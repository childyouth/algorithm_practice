import re
import time
import os

def RidOffSpecialChr(sentence):
    words = re.findall( r'[^(\{\}\[\]\/?.,;:|\)*~`!^\-_+<>@\#$%&\\\=\(\'\"\r\n )]+',sentence)
    """
    split 에 대해서 우선순위를 생각해 보았는데, 예외상황이 있어서 처리를 하지 않기로 했다.
    예를 들어 1,000,000 은 백만이라는 합쳐진 데이터가 유의미한데, 모든 사람들이 콤마 뒤에 스페이스를
     지킬수는 없기때문에 잘못 입력된 "유럽은 사랑스럽지만,위험하다" 라는 문장에서 추출이 "사랑스럽지만위험하다"
    라고 만들어 질 수 있는 위험이 있다. 또한 0.5523 같은 소수점의 경우에도  위와 마찬가지 등의 이유가 있다.
    현재 실습에서는 한국어에 집중하고 있기 때문에 숫자에 있어서 별도의 생각을 하지 않기로 했다. 만약 숫자가 중요하다면
    .과 , 두개를 제외한 특수문자부터 나눈 뒤 각각의 단어에 있어 isInteger 인지 확인 후 제거하는 것이 더 정확한 데이터를
    찾을수 있을것같다.
    """
    return words

def MakeDictionary(file):
    cnt = {}
    while True:
        line = file.readline().strip()
        if not line: break
        words = RidOffSpecialChr(line)
        for w in words:
            if w in cnt.keys():
                cnt[w] += 1
            else:
                cnt[w] = 1
    return cnt;

def PrintOutput(file, cnt):
    for k,v in cnt.items():
        file.write("{} : {} \n".format(v,k))
    return

#
# def CountWords(file, cnt):
#     while True:
#         line = file.readline().strip()
#         if not line: break
#         words = RidOffSpecialChr(line)
#         for w in words:
#             cnt[w] += 1
#     return cnt

n = 0

try:
    n = int(os.path.getsize("KCC150_Korean_sentences_EUCKR.txt")) / (1024.0 * 1024.0)
    print("{:.2f} MB".format(n))
    #f_out.write("걸린 시간 : {:.4f}초".format(t2-t1))
except os.error:
    print("파일을 불러오는데 있어 오류가 있습니다. 다시 시도해주세요")
   # f_out.write("원본 크기를 불러올 수 없습니다")

#f_in = open("input.txt","r", encoding="utf-8")
f_in = open("KCC150_Korean_sentences_EUCKR.txt","r")
f_out = open("output.txt","w", encoding="euc-kr")

f_out.write("원본 크기 : {:.2f} MB\n".format(n))

t1 = time.time()
print("working..")

cnt = {}
cnt = MakeDictionary(f_in)
#cnt = CountWords(f_in,cnt)
PrintOutput(f_out, cnt)

t2 = time.time()
f_out.write("걸린 시간 : {:.4f}초".format(t2-t1))
print(t2 - t1)