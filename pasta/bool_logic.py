# just a link to a serie of videos
# https://www.youtube.com/watch?v=QZwneRb-zqA&list=PLFt_AvWsXl0dPhqVsKt1Ni_46ARyiCGSq&pp=iAQB

a = 1
b = 1
c = 0
d = 0

f = not(a and (not b) and (a or b)) or (not a and b) and not(a or (not b) or not(c))
g = not((c or d) and a and not c and d and (not a and c or not d))

s1 = a and (a or b)
s2 = (a or b) and (not a or b)
s3 = (a and not b or c) and (a or not b)
s4 = (a and b) or c and (not a or b or c) or (a and b) or c and d
s5 = (a or b or c) and (not a or b or c) or (a and b) or c and d
s6 = a or b or not c and b or (a or not c) or not(not a) or b or (not a and c)


# simplified versions 

fs = not a or b
# gs = 
s1s = a # s1s = a and a or a and b
s2s = b
s3s = a or not b
s4s = a and b or c and (not a or b) or c and d
s5s = 1 
# s6s = 
