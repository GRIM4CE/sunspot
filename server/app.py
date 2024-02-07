from app import create_app
from flask_cors import CORS

app = create_app()

CORS(app, resources={
    r"/api/*": {
        "origins": app.config['CORS_ORIGINS'],
        "methods": ["GET"]
    }
})

if __name__ == '__main__':
    app.run(port=app.config['PORT'], debug=app.config['DEBUG'])