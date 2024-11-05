import random
import gym
import numpy as np
import matplotlib.pyplot as plt

def update_q_table(Q, s, a, r, sprime, alpha, gamma):
    best_next_action = np.argmax(Q[sprime])
    Q[s, a] = Q[s, a] + alpha * (r + gamma * Q[sprime, best_next_action] - Q[s, a])
    return Q

def epsilon_greedy(Q, s, epsilon):
    if (random.random() < epsilon):
        return env.action_space.sample()
    else:
        return np.argmax(Q[s])

if __name__ == "__main__":
    env = gym.make("Taxi-v3")

    Q = np.zeros([env.observation_space.n, env.action_space.n])

    alpha = 0.9
    gamma = 0.5
    epsilon = 0.01
    n_epochs = 2000
    max_itr_per_epoch = 10000
    rewards = []

    for e in range(n_epochs):
        r = 0
        S, _ = env.reset()
        #by BOMBA Romain with no brain methode to render the game
        #because Mr ISMAIL FAWAZ told me rending take the most time
        if e == 1999:
            env.close()
            env = gym.make("Taxi-v3", render_mode="human")
            S, _ = env.reset()

        if e >= 2000:
            env.render()
        for _ in range(max_itr_per_epoch):
            A = epsilon_greedy(Q=Q, s=S, epsilon=epsilon)
            Sprime, R, done, _, info = env.step(A)
            r += R
            Q = update_q_table(Q=Q, s=S, a=A, r=R, sprime=Sprime, alpha=alpha, gamma=gamma)
            S = Sprime
            if done:
                break

        print("episode #", e, " : r = ", r)
        rewards.append(r)

    print("Average reward = ", np.mean(rewards))

    plt.plot(range(n_epochs), rewards)
    plt.xlabel('Epochs')
    plt.ylabel('Rewards')
    plt.title('Rewards vs Epochs')
    plt.show()

    print("Training finished.\n")

    env.close()