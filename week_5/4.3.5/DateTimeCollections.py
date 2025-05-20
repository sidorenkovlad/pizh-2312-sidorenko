import json
from datetime_module import DateTime  # Предполагается, что класс DateTime находится в файле datetime_module.py


class DateTimeCollection:
    def __init__(self, data=None):
        """
        Инициализация коллекции.
        :param data: список объектов DateTime или None
        """
        if data is None:
            self._data = []
        else:
            # Проверка, что все элементы - экземпляры DateTime
            if all(isinstance(item, DateTime) for item in data):
                self._data = list(data)
            else:
                raise TypeError("Все элементы должны быть экземплярами класса DateTime")

    def __str__(self):
        """
        Представление коллекции в удобочитаемом виде.
        """
        return '\n'.join(f"{i}: {str(item)}" for i, item in enumerate(self._data))

    def __getitem__(self, index):
        """
        Индексация и срезы.
        """
        return self._data[index]

    def add(self, value):
        """
        Добавление элемента в коллекцию.
        :param value: объект DateTime
        """
        if not isinstance(value, DateTime):
            raise TypeError("Можно добавлять только объекты типа DateTime")
        self._data.append(value)

    def remove(self, index):
        """
        Удаление элемента по индексу.
        :param index: индекс элемента
        """
        if 0 <= index < len(self._data):
            del self._data[index]
        else:
            raise IndexError("Индекс вне диапазона")

    def save(self, filename):
        """
        Сохранение коллекции в JSON-файл.
        :param filename: имя файла
        """
        # Преобразуем объекты DateTime в словари для JSON
        data_to_save = [{'date_str': dt.date(), 'time_str': dt.time()} for dt in self._data]

        with open(filename, 'w', encoding='utf-8') as f:
            json.dump(data_to_save, f, ensure_ascii=False, indent=4)

    def load(self, filename):
        """
        Загрузка коллекции из JSON-файла.
        :param filename: имя файла
        """
        with open(filename, 'r', encoding='utf-8') as f:
            data_loaded = json.load(f)

        self._data = []
        for item in data_loaded:
            date_str = item['date_str']
            time_str = item['time_str']
            # Создаем объект DateTime из строк
            dt_obj = DateTime.from_string(f"{date_str} {time_str}")
            self._data.append(dt_obj)