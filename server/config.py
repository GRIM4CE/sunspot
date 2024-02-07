from dotenv import load_dotenv
import os

load_dotenv()

class Config:
    DEBUG=os.environ.get("DEBUG")
    MONGO_URI=os.environ.get("MONGO_URI")
    PORT=os.environ.get("PORT")
    CORS_ORIGINS=os.environ.get("CORS_ORIGINS")