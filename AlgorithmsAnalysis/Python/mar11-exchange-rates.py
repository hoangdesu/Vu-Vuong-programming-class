# Currency exchange rate

# MYR
#     -> VND
#     -> USD
#     -> Pounds

# enter amount in AUD: 100
# 100 AUD = 1,880,203.58 VND


# 12_345_687_899

# aud = float(input('Enter amount in AUD: '))

# vnd = aud * 18802.58

# # format(vnd, ',')
# print(str(aud) + ' AUD = ' + format(round(vnd, 2), ',') + ' VND')


# Enter amount: 1,880,258
# Enter currency: VND | AUD | USD
# Convert to: AUD | VND | | USD

# 1,880,258 VND = 100 AUD


# converted = 0
# if currency == 'VND':
#     if target_currency == 'AUD':
#         converted = amount / 18_821.95
#     elif target_currency == 'USD':
#         converted = amount / 26_240.00
# elif currency == 'AUD':
#     if target_currency == 'VND':
#         converted = amount * 18_821.95
#     elif target_currency == 'USD':
#         converted = amount / 1.39
# elif currency == 'AUD':
#     if target_currency == 'VND':
#         converted = amount * 18_821.95
#     elif target_currency == 'USD':
#         converted = amount / 1.39
        
# print(converted)

# HashMap -> Dictionary

import sys

exchange_rates = {
    'VND': {
        'AUD': 0.000053,
        'USD': 0.000038
    },
    'AUD': {
        'VND': 18_847.60,
        'USD': 0.72
    },
    'USD': {
        'VND': 26_250.00,
        'AUD': 1.39
    }
}

amount = float(input('Enter amount: '))

currency = input('Enter currency: ')
if currency not in exchange_rates:
    print(f'Error. Currency {currency} not found')
    sys.exit()

# => exchange_rates[currency] exists => will NEVER throw error

target_currency = input('Convert to: ')
if target_currency not in exchange_rates[currency]:
    print(f'Error. Target currency {target_currency} not found')
    sys.exit()


converted = amount * exchange_rates[currency][target_currency]

# print(converted)

# String format
# string.format()
# f-string
print(f'{format(amount, ',')} {currency} = {converted:,} {target_currency}')


HW:
    - add a few more currencies
    - also show other currencies
        100 USD
        VND
        100 USD = 1,880,000 VND
        100 USD = 139.41 AUD
        100 USD = 15,810.20 JPY
        100 USD = 687.70 CNY
