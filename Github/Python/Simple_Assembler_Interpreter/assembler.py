def simple_assembler(program):
    ram = {}
    point = 0

    while point < len(program):
        command = program[point].split(" ")

        if "mov" in command[0]:
            if command[2].isalpha():
                ram[command[1]] = ram.get(command[2], 0)
            else:
                ram[command[1]] = int(command[2])

        elif "inc" in command[0]:
            if command[1] in ram:
                ram[command[1]] += 1

        elif "dec" in command[0]:
            if command[1] in ram:
                ram[command[1]] -= 1

        elif "jnz" in command[0]:
            if (command[1].isdigit() and int(command[1]) != 0) or (command[1] in ram and ram[command[1]] != 0):
                point += int(command[2])
                continue

        point += 1

    return ram