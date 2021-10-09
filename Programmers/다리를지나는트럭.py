def solution(bridge_length, weight, truck_weights):
    answer = 0
    truck_bridge = [0] * bridge_length
    while len(truck_bridge):
        answer += 1
        truck_bridge.pop(0)
        if truck_weights:
            if sum(truck_bridge) + truck_weights[0] <= weight:
                truck_bridge.append(truck_weights.pop(0))
            else:
                truck_bridge.append(0)
    return answer