import pygame
import random
import sys

# Инициализация Pygame
pygame.init()

# Константы
SCREEN_WIDTH = 640
SCREEN_HEIGHT = 480
CELL_SIZE = 20  # Размер клетки (змейка и яблоко)
FPS = 10

# Цвета (RGB)
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
GREEN = (0, 255, 0)
RED = (255, 0, 0)


class GameObject:
    """
    Базовый класс для игровых объектов.
    """

    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y

    def draw(self, surface):
        """
        Метод для отрисовки объекта. Реализуется в подклассах.
        """
        raise NotImplementedError("Метод draw должен быть реализован в подклассе.")


class Snake(GameObject):
    """
    Класс змеи.
    """

    def __init__(self):
        # Начинаем с длины 3 и позиции по центру экрана
        super().__init__(SCREEN_WIDTH // 2, SCREEN_HEIGHT // 2)
        self.segments = [
            (self.x, self.y),
            (self.x - CELL_SIZE, self.y),
            (self.x - 2 * CELL_SIZE, self.y)
        ]
        self.direction = 'RIGHT'
        self.new_direction = self.direction

    def change_direction(self, new_direction):
        """
        Меняет направление движения змеи.
        Предотвращает обратное движение.
        """
        opposites = {'UP': 'DOWN', 'DOWN': 'UP', 'LEFT': 'RIGHT', 'RIGHT': 'LEFT'}
        if new_direction != opposites.get(self.direction):
            self.new_direction = new_direction

    def move(self):
        """
        Перемещает змею в текущем направлении.
        """
        head_x, head_y = self.segments[0]
        if self.new_direction:
            self.direction = self.new_direction

        if self.direction == 'UP':
            new_head = (head_x, head_y - CELL_SIZE)
        elif self.direction == 'DOWN':
            new_head = (head_x, head_y + CELL_SIZE)
        elif self.direction == 'LEFT':
            new_head = (head_x - CELL_SIZE, head_y)
        elif self.direction == 'RIGHT':
            new_head = (head_x + CELL_SIZE, head_y)

        # Добавляем новый головной сегмент
        self.segments.insert(0, new_head)
        # Удаляем хвост
        self.segments.pop()

    def grow(self):
        """
        Увеличивает длину змеи при поедании яблока.
        Для этого не удаляем хвост при следующем движении.
        """
        # Просто не удаляем хвост при следующем движении
        pass

    def check_self_collision(self):
        """
        Проверяет столкновение змеи с самим собой.
        Возвращает True если есть столкновение.
        """
        return len(self.segments) != len(set(self.segments))

    def draw(self, surface):
        """
        Отрисовка змеи на поверхности.
        """
        for segment in self.segments:
            rect = pygame.Rect(segment[0], segment[1], CELL_SIZE, CELL_SIZE)
            pygame.draw.rect(surface, GREEN, rect)


class Apple(GameObject):
    """
    Класс яблока.
    """

    def __init__(self):
        super().__init__(0, 0)
        self.position = (0, 0)

    def spawn(self, snake_segments):
        """
        Располагает яблоко в случайной позиции,
        которая не совпадает с сегментами змеи.

        :param snake_segments: список сегментов змеи для исключения перекрытия
        """

        while True:
            x = random.randint(0, (SCREEN_WIDTH - CELL_SIZE) // CELL_SIZE) * CELL_SIZE
            y = random.randint(0, (SCREEN_HEIGHT - CELL_SIZE) // CELL_SIZE) * CELL_SIZE
            if (x, y) not in snake_segments:
                break

        self.position = (x, y)

    def draw(self, surface):
        """
        Отрисовка яблока на поверхности.

        :param surface: поверхность для отрисовки
        """

    pygame.draw.rect(surface, RED,
                     pygame.Rect(self.position[0], self.position[1], CELL_SIZE, CELL_SIZE))


def main():
    """
    Основная функция запуска игры.
    """

    screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
    pygame.display.set_caption("Змейка")

    clock = pygame.time.Clock()

    snake = Snake()
    apple = Apple()
    apple.spawn(snake.segments)

    score = 0
    game_over = False

    while not game_over:

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_UP:
                    snake.change_direction('UP')
                elif event.key == pygame.K_DOWN:
                    snake.change_direction('DOWN')
                elif event.key == pygame.K_LEFT:
                    snake.change_direction('LEFT')
                elif event.key == pygame.K_RIGHT:
                    snake.change_direction('RIGHT')

        snake.move()

        # Проверка столкновения с границами экрана
        head_x, head_y = snake.segments[0]
        if (
                head_x < 0 or head_x >= SCREEN_WIDTH or
                head_y < 0 or head_y >= SCREEN_HEIGHT or
                snake.check_self_collision()
        ):
            game_over = True

        # Проверка поедания яблока
        if snake.segments[0] == apple.position:
            score += 1
            # Добавляем сегмент в конец змеи вместо удаления хвоста при следующем движении
            snake.segments.append(snake.segments[-1])
            apple.spawn(snake.segments)

        # Отрисовка игрового поля и объектов
        screen.fill(BLACK)
        snake.draw(screen)
        apple.draw(screen)

        # Отображение счета
        font = pygame.font.SysFont(None, 36)
        score_text = font.render(f"Score: {score}", True, WHITE)
        screen.blit(score_text, (10, 10))

        pygame.display.flip()

        clock.tick(FPS)

    # Игра окончена — вывод сообщения и завершение программы


font_game_over = pygame.font.SysFont(None, 72)
text_surface = font_game_over.render("Game Over", True, RED)
rect_text = text_surface.get_rect(center=(SCREEN_WIDTH // 2, SCREEN_HEIGHT // 2))

screen.blit(text_surface, rect_text)
pygame.display.flip()

# Задержка перед закрытием окна
pygame.time.wait(3000)
pygame.quit()

if __name__ == "__main__":
    main()