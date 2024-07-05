import pygame
import numpy as np

# Constants
WIDTH, HEIGHT = 800, 600
DAMPING = 0.99
WAVE_SPEED = 100.5
WATER_COLOR = (0, 105, 148)

# Initialize Pygame
pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Realistic Water Simulation")
clock = pygame.time.Clock()

# Height maps
current_height = np.zeros((WIDTH, HEIGHT), dtype=np.float32)
previous_height = np.zeros((WIDTH, HEIGHT), dtype=np.float32)
velocities = np.zeros((WIDTH, HEIGHT), dtype=np.float32)

# Function to update the water surface
def update_water_surface():
    global current_height, previous_height, velocities
    
    # Calculate new heights
    new_height = np.copy(current_height)
    for x in range(1, WIDTH - 1):
        for y in range(1, HEIGHT - 1):
            height = (current_height[x - 1, y] + current_height[x + 1, y] +
                      current_height[x, y - 1] + current_height[x, y + 1]) / 2
            new_height[x, y] = height - previous_height[x, y]
            new_height[x, y] *= DAMPING

    # Update velocities
    velocities = new_height - current_height

    # Swap height maps
    previous_height = np.copy(current_height)
    current_height = new_height

# Function to disturb the water surface
def disturb(x, y, radius, height):
    for i in range(-radius, radius):
        for j in range(-radius, radius):
            if 0 <= x + i < WIDTH and 0 <= y + j < HEIGHT:
                if i**2 + j**2 < radius**2:
                    current_height[x + i, y + j] = height

# Main loop
running = True
while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        elif event.type == pygame.MOUSEBUTTONDOWN:
            mouse_x, mouse_y = event.pos
            disturb(mouse_x, mouse_y, 10, 100)

    # Update water surface
    update_water_surface()

    # Render water surface
    screen.fill(WATER_COLOR)
    for x in range(WIDTH):
        for y in range(HEIGHT):
            color_intensity = min(255, max(0, int(current_height[x, y] + 128)))
            color = (0, color_intensity, 255)
            screen.set_at((x, y), color)

    pygame.display.flip()
    clock.tick(120)

pygame.quit()
