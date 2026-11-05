import ollama

print('hello ollama')

conversation_history = [
    {
        'role': 'system',
        'content': 'Always end an assistant answer with a "meow!"'
    }
]

while True:
    prompt = input('\n> User: ')

    conversation_history.append(
        {
            'role': 'user',
            'content': prompt
        }
    )

    response = ollama.chat(
        model='llama3.1:8b',
        messages=conversation_history
    )

    print(response.message.content)
    # print('> Bot: ' + response.get('message').get('content'))

    conversation_history.append({
        'role': 'assistant',
        'content': response.message.content
    })

    # print(f'\n>> {conversation_history=}')


# i am
# i'm

# he's vs he is

# // TODO: stream