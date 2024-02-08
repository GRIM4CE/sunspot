import { MongoClient } from 'mongodb';

let mongoClient = null;

const connectToDatabase = async (uri) => {
    if (mongoClient) {
        console.log("Using existing MongoDB client");
        return mongoClient;
    }

    mongoClient = new MongoClient(uri);
    await mongoClient.connect();
    console.log("New MongoDB client connected");
    return mongoClient;
};

export const handler = async (event, context) => {
    const body = JSON.parse(event.body)

    if(!body.lux) return {
        statusCode: 422,
        body: JSON.stringify({ error: "Missing { lux: number } in event" })
    };
    
    context.callbackWaitsForEmptyEventLoop = false;

    try {
        const uri = process.env.MONGO_URI;
        const client = await connectToDatabase(uri);
        const db = client.db("sunspot_db_v2");
        const collection = db.collection("sunspot_light");
        const time = new Date()

        const document = {
            timestamp: time,
            lux: body.lux,
            temperature: body.temperature,
            humidity: body.humidity
        };

        const result = await collection.insertOne(document);

        return {
            statusCode: 200,
            body: JSON.stringify(result)
        };
    } catch (error) {
        console.error("Error in MongoDB operation", error);
        return {
            statusCode: 500,
            body: JSON.stringify({ error: "Error connecting to MongoDB" })
        };
    }
};