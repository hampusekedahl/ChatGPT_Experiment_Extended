import PySimpleGUI as sg
import pyperclip

types = [
    'Solve this programming problem with ',
    'Solve this programming problem as runtime and memory efficient as you can with '
]

templateString = 'This is the code starting template'

layout = [
    [sg.Text('Language:', pad=((3, 0), 0)), sg.OptionMenu(values=('C++', 'C', 'Python', 'C#', 'Java'), size=(20, 1))],
    [sg.Text('Type:', pad=((3, 0), 0)), sg.OptionMenu(values=('Just Solve', 'Runtime And Memory'), size=(20, 1))],
    [sg.Text('Description:', pad=((3, 0), 0)), sg.Input(size=(44, 1), do_not_clear=False, background_color='white', text_color='black')],
    [sg.Text('Template:', pad=((3, 0), 0)), sg.Input(size=(44, 1), do_not_clear=False, background_color='white', text_color='black')],
    [sg.Button('Generate & Copy', button_color=('white', 'black'), key='-Copy-'), sg.Button('Reset', button_color=('white', 'firebrick3'), key='-Reset-')],
    [sg.Text('Error:')],
    [sg.Text('Input:', pad=((3, 0), 0)), sg.Input(size=(44, 1), do_not_clear=False, background_color='white', text_color='black')],
    [sg.Text('Output:', pad=((3, 0), 0)), sg.Input(size=(44, 1), do_not_clear=False, background_color='white', text_color='black')],
    [sg.Text('Expected:', pad=((3, 0), 0)), sg.Input(size=(44, 1), do_not_clear=False, background_color='white', text_color='black')],
    [sg.Button('Error Copy', button_color=('white', 'black'), key='-Copy Error-')]
]

window = sg.Window(
    "PromptTool-DVA331",
    layout,
    size=(400, 400),
    default_element_size=(12, 1),
    text_justification='rw',
    auto_size_text=False,
    auto_size_buttons=False,
    default_button_element_size=(22, 1),
    finalize=True
)

recording = have_data = False
while True:
    event, values = window.read()
    if event == sg.WIN_CLOSED:
        break
    if event == '-Copy-': 
        if values[1] == 'Just Solve':
            type = types[0]
        elif values[1] == 'Runtime And Memory':
            type = types[1]
        pyperclip.copy(type + values[0] + ' "' + values[2] + '". ' + templateString + ' "' + values[3] + '".')
        print(pyperclip.paste())
    if event == '-Copy Error-':
        pyperclip.copy('With input "' + values[4] + '" output was "' + values[5] + '" but expected result was "' + values[6] + '".')
        print(pyperclip.paste())

window.close()