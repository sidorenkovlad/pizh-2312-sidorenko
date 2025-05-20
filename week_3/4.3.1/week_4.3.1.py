class Roman:
    # Таблица для преобразования арабских чисел в римские
    _int_to_roman_map = [
        (1000, "M"), (900, "CM"), (500, "D"), (400, "CD"),
        (100, "C"), (90, "XC"), (50, "L"), (40, "XL"),
        (10, "X"), (9, "IX"), (5, "V"), (4, "IV"),
        (1, "I")
    ]

    def __init__(self, value):
        """
        Инициализация объекта Roman.
        value: может быть строкой с римским числом или целым числом.
        """
        if isinstance(value, int):
            if value <= 0:
                raise ValueError("Число должно быть положительным")
            self.value = value
            self.roman = self.int_to_roman(value)
        elif isinstance(value, str):
            self.roman = value.upper()
            self.value = self.roman_to_int(self.roman)
        else:
            raise TypeError("Значение должно быть строкой или целым числом")

    def __str__(self):
        return self.roman

    def __add__(self, other):
        if isinstance(other, Roman):
            return Roman(self.value + other.value)
        else:
            return NotImplemented

    def __sub__(self, other):
        if isinstance(other, Roman):
            result = self.value - other.value
            if result <= 0:
                raise ValueError("Результат должен быть положительным")
            return Roman(result)
        else:
            return NotImplemented

    def __mul__(self, other):
        if isinstance(other, Roman):
            return Roman(self.value * other.value)
        else:
            return NotImplemented

    def __truediv__(self, other):
        if isinstance(other, Roman):
            if other.value == 0:
                raise ZeroDivisionError("Деление на ноль")
            result = self.value / other.value
            # Возвращаем целое число результата деления
            return Roman(int(result))
        else:
            return NotImplemented

    @staticmethod
    def roman_to_int(roman_str):
        roman_map = {
            'I': 1,
            'IV': 4,
            'V': 5,
            'IX': 9,
            'X': 10,
            'XL': 40,
            'L': 50,
            'XC': 90,
            'C': 100,
            'CD': 400,
            'D': 500,
            'CM': 900,
            'M': 1000
        }
        i = 0
        total = 0
        while i < len(roman_str):
            # Проверяем двухсимвольные символы
            if i + 1 < len(roman_str) and roman_str[i:i+2] in roman_map:
                total += roman_map[roman_str[i:i+2]]
                i += 2
            else:
                total += roman_map[roman_str[i]]
                i += 1
        return total

    @staticmethod
    def int_to_roman(number):
        result = ""
        for value, symbol in Roman._int_to_roman_map:
            while number >= value:
                result += symbol
                number -= value
        return result


# Пример использования:

r1 = Roman("XIV")   # 14
r2 = Roman(3)       # III

print(f"{r1} + {r2} =", r1 + r2)   # XVII (17)
print(f"{r1} - {r2} =", r1 - r2)   # XI (11)
print(f"{r1} * {r2} =", r1 * r2)   # XLII (42)
print(f"{r1} / {r2} =", r1 / r2)   # IV (4)