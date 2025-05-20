import json
from datetime import datetime, timedelta

class DateTime:
    def __init__(self, year, month, day, hour=0, minute=0, second=0):
        self._dt = datetime(year, month, day, hour, minute, second)

    def __str__(self):
        return self._dt.strftime("%Y-%m-%d %H:%M:%S")

    def __add__(self, other):
        if isinstance(other, timedelta):
            new_dt = self._dt + other
            return DateTime(new_dt.year, new_dt.month, new_dt.day,
                            new_dt.hour, new_dt.minute, new_dt.second)
        elif isinstance(other, DateTime):
            # Возвращает разницу между двумя датами
            delta = self._dt - other._dt
            return delta
        else:
            raise TypeError("Unsupported operand type(s) for +: 'DateTime' and '{}'".format(type(other)))

    def __sub__(self, other):
        if isinstance(other, DateTime):
            delta = self._dt - other._dt
            return delta
        elif isinstance(other, timedelta):
            new_dt = self._dt - other
            return DateTime(new_dt.year, new_dt.month, new_dt.day,
                            new_dt.hour, new_dt.minute, new_dt.second)
        else:
            raise TypeError("Unsupported operand type(s) for -: 'DateTime' and '{}'".format(type(other)))

    @classmethod
    def from_string(cls, str_value):
        dt = datetime.strptime(str_value, "%Y-%m-%d %H:%M:%S")
        return cls(dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second)

    def save(self, filename):
        data = {
            'year': self._dt.year,
            'month': self._dt.month,
            'day': self._dt.day,
            'hour': self._dt.hour,
            'minute': self._dt.minute,
            'second': self._dt.second
        }
        with open(filename, 'w') as f:
            json.dump(data, f)

    @classmethod
    def load(cls, filename):
        with open(filename, 'r') as f:
            data = json.load(f)
        return cls(data['year'], data['month'], data['day'],
                   data['hour'], data['minute'], data['second'])

    # Дополнительные методы и свойства

    @property
    def date(self):
        """Возвращает дату в виде строки YYYY-MM-DD"""
        return self._dt.strftime("%Y-%m-%d")

    @property
    def time(self):
        """Возвращает время в виде строки HH:MM:SS"""
        return self._dt.strftime("%H:%M:%S")

    def is_weekend(self):
        """Проверяет является ли дата выходным днем (суббота или воскресенье)"""
        return self._dt.weekday() >= 5

    def add_days(self, days):
        """Добавляет указанное количество дней"""
        new_dt = self._dt + timedelta(days=days)
        return DateTime(new_dt.year,new_dt.month,new_dt.day,new_dt.hour,new_dt.minute,new_dt.second)

    def difference_in_days(self, other):
        """Возвращает разницу в днях между двумя датами"""
        if not isinstance(other, DateTime):
            raise TypeError("Expected a DateTime object")
        delta = abs(self._dt - other._dt)
        return delta.days