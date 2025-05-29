prices = []

def decide_action(price):
    prices.append(price)
    short_window = 3
    long_window = 5

    if len(prices) < long_window:
        return "HOLD"

    short_ma = sum(prices[-short_window:]) / short_window
    long_ma = sum(prices[-long_window:]) / long_window

    if short_ma > long_ma:
        return "BUY"
    elif short_ma < long_ma:
        return "SELL"
    else:
        return "HOLD"
