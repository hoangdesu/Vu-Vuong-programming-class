# key-value pairs

capitals = {
    'vietnam': 'hue',
    'japan': 'tokyo',
    'australia': 'canberra',
    'vietnam': 'hanoi', # overwrite hue
    'korea': 'seoul'
}

# Access values inside a dict
print(capitals['vietnam'])

# bracket notation: make sure key exists before getting the value
# print(capitals['korea'])

if 'korea' in capitals:
    print(capitals['korea'])
else:
    print('key "korea" doesnt exists in dict')

print(capitals.get('japan'))
print(capitals.get('china')) # returns None, not throwing error


# Add more entries
capitals['china'] = 'beijing'
print(capitals.get('china'))


# | country | capital |


# Displaying keys, values and keys + values (items)
print('keys:', capitals.keys())
print('values:', capitals.values())
print('items:', capitals.items())


# Iterate (loop) over a dict
print(f'{"| country":<12}   | capital    |')
print('-' * 29)
for country in capitals:
    print(f'| {country:<12} | {capitals[country]:<10} |')


for entry in capitals.items():
    print(f'capital {entry[0]} is {entry[1]}')
    


# Variable naming conventions
# camelCase: thisIsAVeryLongVariableName
# snake_case: this_is_a_very_long_variable_name
# PascalCase: ThisIsAVeryLongVariableName


vuong = {
    # nested dict
    'name': {
        'first': 'Vương',
        'last': 'Nguyễn',
        'english': {
            'first': 'Justin',
            'last': 'Nguyen'
        }
    },
    'birth_year': 2005,
    'games': ['Valorant', 'Hades', 'E33'],
    'is_happy': True
}


print(f"{vuong['name']['english']['first']} {vuong['name']['last']} ({2026 - vuong['birth_year']} yo) is playing {vuong['games'][1]}")
