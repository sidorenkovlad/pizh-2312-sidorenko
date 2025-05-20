from datetime_module import DateTime

def вывод_меню():
    print("\nВыберите действие:")
    print("1. Создать дату из параметров")
    print("2. Создать дату из строки")
    print("3. Показать текущую дату")
    print("4. Добавить дни к дате")
    print("5. Вычесть дни из даты")
    print("6. Разница между двумя датами")
    print("7. Сохранить дату в файл")
    print("8. Загрузить дату из файла")
    print("9. Проверить, является ли дата выходным днем")
    print("10. Добавить определенное количество дней")
    print("0. Выйти")

def получить_число(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            print("Пожалуйста, введите число.")

def main():
    current_date = None

    while True:
        вывод_меню()
        выбор = input("Введите номер действия: ")

        if выбор == '1':
            y = получить_число("Введите год: ")
            m = получить_число("Введите месяц: ")
            d = получить_число("Введите день: ")
            h = получить_число("Введите часы (по умолчанию 0): ") or 0
            mi = получить_число("Введите минуты (по умолчанию 0): ") or 0
            s = получить_число("Введите секунды (по умолчанию 0): ") or 0
            current_date = DateTime(y, m, d, h, mi, s)
            print(f"Создана дата: {current_date}")

        elif выбор == '2':
            строка = input("Введите дату и время в формате ГГГГ-ММ-ДД ЧЧ:ММ:СС: ")
            try:
                current_date = DateTime.from_string(строка)
                print(f"Создана дата: {current_date}")
            except Exception as e:
                print(f"Ошибка при парсинге строки: {e}")

        elif выбор == '3':
            if current_date:
                print(f"Текущая дата: {current_date}")
            else:
                print("Нет выбранной даты.")

        elif выбор == '4':
            if current_date:
                days = получить_число("Введите количество дней для добавления: ")
                current_date = current_date.add_days(days)
                print(f"Обновленная дата: {current_date}")
            else:
                print("Нет выбранной даты.")

        elif выбор == '5':
            if current_date:
                days = получить_число("Введите количество дней для вычитания: ")
                current_date -= timedelta(days=days)
                print(f"Обновленная дата: {current_date}")
            else:
                print("Нет выбранной даты.")

        elif выбор == '6':
            if current_date:
                y2 = получить_число("Введите год второй даты: ")
                m2 = получить_число("Введите месяц второй даты: ")
                d2 = получить_число("Введите день второй даты: ")
                dt2 = DateTime(y2, m2, d2)
                разница = current_date - dt2
                print(f"Разница между датами: {разница}")
            else:
                print("Нет выбранной даты.")

        elif выбор == '7':
            if current_date:
                filename = input("Введите имя файла для сохранения (например data.json): ")
                try:
                    current_date.save(filename)
                    print(f"Дата сохранена в файл {filename}")
                except Exception as e:
                    print(f"Ошибка при сохранении файла: {e}")
            else:
                print("Нет выбранной даты.")

        elif выбор == '8':
            filename = input("Введите имя файла для загрузки (например data.json): ")
            try:
                current_date = DateTime.load(filename)
                print(f"Дата загружена: {current_date}")
            except Exception as e:
                print(f"Ошибка при загрузке файла: {e}")

        elif выбор == '9':
            if current_date:
                is_weekend = "да" if current_date.is_weekend() else "нет"
                print(f"Является ли дата выходным днем? {is_weekend}")
            else:
                print("Нет выбранной даты.")

        elif выбор == '10':
            if current_date:
                days_to_add = получить_число("Введите количество дней для добавления: ")
                current_date = current_date.add_days(days_to_add)
                print(f"Обновленная дата: {current_date}")
            else:
                print("Нет выбранной даты.")

        elif выбор == '0':
            print("Выход из программы.")
            break

        else:
            print("Некорректный ввод. Попробуйте снова.")

if __name__ == "__main__":
    main()