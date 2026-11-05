import ollama

print('hello ollama')

while True:
    prompt = input('\n> User: ')

    response = ollama.generate(
        model='llama3.1:8b',
        prompt=prompt
    )

    # print(response['response'])
    print('> Bot: ' + response.get('response'))
