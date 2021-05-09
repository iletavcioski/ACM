def dropka(x):
    a, b = x.split(' ')[1].split('/')
    a = int(a)
    b = int(b)
    return a / b

student_string = inp[0]
student_p = dropka(student_string)

vzd_string = inp[1]
vzd_p = dropka(vzd_string)


def parse_broj(x):
    x = x.replace('.', '').replace(',', '')
    return int(x)

def parse(x):
    x = x.split()
    
    kod = x[0]
    return kod, parse_broj(x[1]), parse_broj(x[2]), parse_broj(x[3])


dic = {
    '1101': (0, 0, 0),
    '1101/1': (0, 0, 0),
    '1101/2': (0, 0, 0),
    '1105': (0, 0, 0),
    '1211': (0, 0, 0),
    '1230': (0, 0, 0)
}


for x in inp[2:]:
    kod, bruto, prispevki, akontacija = parse(x)
    x, y, z = dic[kod]
    dic[kod] = (x + bruto, y + prispevki, z + akontacija)


dohodek = 0
for x in dic:
    dohodek += dic[x][0]


prispevki = 0
for x in dic:
    prispevki += dic[x][1]


obdavcen_bruto_dohodek = dic['1101'][0] + dic['1211'][0] + dic['1230'][0]
placa_davcna_osnova = dic['1101'][0] - dic['1101'][1]
stud_davcna_osnova = dic['1211'][0] - dic['1211'][1] - 0.1 * dic['1211'][0]
treto_davcna_osnova = dic['1230'][0] - dic['1230'][1] - 0.1 * dic['1230'][0]

if student_p > 0:
    stud_davcna_osnova -= 350000
    if stud_davcna_osnova < 0:
        stud_davcna_osnova = 0

davcna_osnova = placa_davcna_osnova + stud_davcna_osnova + treto_davcna_osnova

x = 0
if obdavcen_bruto_dohodek >= 1331683:
    x = 350000
else:
    x = 350000 + (1870038 - 1.40427 * obdavcen_bruto_dohodek)    
davcna_osnova -= (1 - vzd_p) * x

if davcna_osnova < 0:
    davcna_osnova = 0

# lims = [(850000, 0.16),
#         (2500000, 0.26),
#         (5000000, 0.33),
#         (7200000, 0.39),
#         (1000000000, 0.50)]

lims = [(0, 0.16),
        (850000, 0.10),
        (2500000, 0.07),
        (5000000, 0.06),
        (7200000, 0.11)]

danok = 0
prethoden_limit = 0
for lim in lims:
    clim, procent = lim
    if davcna_osnova >= clim:
        danok += (davcna_osnova - clim) * procent


neto_dohodek = dohodek - prispevki - danok


proc = (dohodek - neto_dohodek) / dohodek * 10000


akontacija = 0
for x in dic:
    akontacija += dic[x][2]


def f(x):
    x = round(x)
    xd100 = x // 100
    ostanato = x % 100
    left = f"{xd100:,}".replace(',', '.')
    right = f"{ostanato:2d}".replace(' ', '0')
    return ','.join([left, right])


krajno = danok - akontacija

if krajno < 0:
    print('-', end = '')
    krajno = abs(krajno)
print(f(krajno))
print('%s %s %s %s %s%%' % (f(dohodek), f(prispevki), f(danok), f(neto_dohodek), f(proc)))