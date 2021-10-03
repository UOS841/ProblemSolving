import math

def convert_time(hhmm):
    hh, mm = hhmm.split(":")
    return int(hh) * 60 + int(mm) 

def calc_fee(parking_time, fees):
    default_time, default_fee, unit_time, unit_fee = fees

    if parking_time - default_time < 0:
        return default_fee
    else:
        parking_fee = math.ceil((parking_time - default_time) / (unit_time))
        return parking_fee * unit_fee + default_fee

def solution(fees, records):
    total_times = dict()
    car_times = dict()
    parking_fee = dict()
    parked_cars = list()

    for record in records:
        time, car_id, is_in = record.split(' ')
        
        cur_time = convert_time(time)
        if is_in == 'IN':
            if car_id not in total_times:
                total_times[car_id] = 0

            car_times[car_id] = cur_time
            parking_fee[car_id] = 0
            parked_cars.append(car_id)
        else:
            parking_time = cur_time - car_times[car_id]
            total_times[car_id] += parking_time

            parked_cars.remove(car_id)
        
    for car_id in parked_cars:
        parking_time = convert_time('23:59') - car_times[car_id]
        total_times[car_id] += parking_time
        
    
    for car_id in total_times:
        parking_fee[car_id] = calc_fee(total_times[car_id], fees)

    parking_fee = sorted(parking_fee.items())
    answer = list()
    for car_id, payments in parking_fee:
        answer.append(payments)
    
    return answer
    