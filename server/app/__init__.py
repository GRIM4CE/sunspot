from flask import Flask
from config import Config
from .api.routes import api_bp
from .cache import cache 

from flask_cors import CORS


def create_app():
    app = Flask(__name__)
    app.config.from_object(Config)


    CORS(app, resources={
        r"/api/*": {
            "origins": app.config['CORS_ORIGINS'],
            "methods": ["GET"]
        }
    })
    
    cache.init_app(app)
    app.register_blueprint(api_bp, url_prefix='/api')

    return app
