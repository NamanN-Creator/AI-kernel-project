import time
import psutil
import logging

# Setup logging to a file
logging.basicConfig(filename='ai_daemon.log', level=logging.INFO, format='%(asctime)s %(message)s')

def get_metrics():
    cpu = psutil.cpu_percent(interval=1)
    mem = psutil.virtual_memory().percent
    return f"CPU Usage: {cpu}%, Memory Usage: {mem}%"

def main():
    logging.info("AI Daemon started")
    try:
        while True:
            metrics = get_metrics()
            logging.info(metrics)
            time.sleep(5)  # wait 5 seconds before next reading
    except KeyboardInterrupt:
        logging.info("AI Daemon stopped")

if __name__ == "__main__":
    main()
