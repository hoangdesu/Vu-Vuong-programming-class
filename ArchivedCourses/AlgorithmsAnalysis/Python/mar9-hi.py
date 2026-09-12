# print('hi')

# # REPL: Read-Eval-Print Loop >>>

# # str
# name = input('what is your name: ')

# print('hello ' + name)


# Dynamically-typed languages
# JS: let name = 'Vuong'
# const vs let vs var


# Type casting: str -> int

# a = int(input('a = '))
# # a = float(input('a = '))
# b = float(input('b = '))


# c = a + b # '1' + '2'
# print('c = ' + str(c))

# Int(5.5) -> 5

# Intepreted languages: JS, Py
# Compiled languages: C/C++/Java (50%)


year = int(input('when were you born: '))
age = 2026 - year

# indentations to separate out blocks of code

print('You are ' + str(age) + ' years old')

if age < 18:
    if 1 <= age <= 13:
        print('Baby')
    else:
        print('You are a child')
# elif age >= 18 and age <= 65
elif 18 <= age <= 65:
    print('You are an adult')
else:
    print('You are a senior')
