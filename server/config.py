from dotenv import load_dotenv
import os

load_dotenv()

class Config:
    DEBUG=False
    MONGO_URI=os.environ.get("MONGO_URI")