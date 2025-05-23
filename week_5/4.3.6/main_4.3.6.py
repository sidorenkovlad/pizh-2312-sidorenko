# main.py

from tickets import *

def тестировать_bilet():
    print("Создаем билет с ограничением на 5 поездок")
    билет1 = БилетСОграничениемПоездок(100, 5)
    билет1.показать_статус()

    for i in range(7):  # попытка списать больше раз, чем есть лимит
        print(f"\nПопытка списания поездки {i+1}")
        билет1.списать_поездку()

    билет1.показать_статус()

    print("\nСоздаем безлимитный билет")
    билет2 = БезлимитныйБилет(200)
    билет2.показать_статус()

    for i in range(3):  # несколько поездок
        print(f"\nПопытка списания безлимитной поездки {i+1}")
        билет2.списать_поездку()

    билет2.показать_статус()

if __name__ == "__main__":
    тестировать_bilet()