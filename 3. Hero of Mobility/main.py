import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from PID_controller import PIDController, PositionController

def animate_position_and_speed(X_position_axis, Y_position_axis, Vx_position_axis, Vy_position_axis):
    fig, (ax1, ax2, ax3) = plt.subplots(3, 1, figsize=(8, 6))
    line1, = ax1.plot([], [], 'b-', label='Position')
    ax1.set_xlim(min(X_position_axis), 1.5 * max(X_position_axis))
    ax1.set_ylim(min(Y_position_axis), 1.5 * max(Y_position_axis))
    ax1.set_xlabel('X Position')
    ax1.set_ylabel('Y Position')
    ax1.set_title('Position')
    ax1.legend()

    line2, = ax2.plot([], [], 'r-', label='X Velocity')
    ax2.set_xlim(0, len(Vx_position_axis))
    ax2.set_ylim(min(Vx_position_axis), 1.5 * max(Vx_position_axis))
    ax2.set_xlabel('Time')
    ax2.set_ylabel('X Velocity')
    ax2.legend()

    line3, = ax3.plot([], [], 'g-', label='Y Velocity')
    ax3.set_xlim(0, len(Vy_position_axis))
    ax3.set_ylim(min(Vy_position_axis), 1.5 * max(Vy_position_axis))
    ax3.set_xlabel('Time')
    ax3.set_ylabel('Y Velocity')
    ax3.legend()

    def update(frame):
        line1.set_data(X_position_axis[:frame], Y_position_axis[:frame])
        line2.set_data(range(frame), Vx_position_axis[:frame])
        line3.set_data(range(frame), Vy_position_axis[:frame])
        return line1, line2, line3

    ani = FuncAnimation(fig, update, frames=len(X_position_axis), blit=True)
    plt.show()

if __name__ == "__main__":
    Kp = 0.2
    Ki = 0.0
    Kd = 0.01
    sample_time = 0.1

    pid_controller = PIDController(Kp, Ki, Kd, sample_time)

    # Set desired position
    X_setpoint, Y_setpoint = [float(x) for x in input("Enter position (x,y): ").split()]

    position_controller = PositionController(pid_controller)
    X_position_axis, Y_position_axis, Vx_position_axis, Vy_position_axis = position_controller.control(X_setpoint, Y_setpoint)

    # Plot the position and speed trajectory
    animate_position_and_speed(X_position_axis, Y_position_axis, Vx_position_axis, Vy_position_axis)
