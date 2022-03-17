import java.io.*;
import java.net.*;

public class TCPServer {

	public static void main(String argv[]) throws Exception
	{
		String clientSentence;
		String capitalizedSentence;

		ServerSocket welcomeSocket = new ServerSocket(8989);

		System.out.println("Server is ready for incomign connections");
		while (true) {
			Socket connectionSocket = welcomeSocket.accept();
			System.out.println("a client is connected..");
			BufferedReader inFromClient =
				new BufferedReader(new InputStreamReader(connectionSocket.getInputStream()));
			DataOutputStream outToClient =
				new DataOutputStream(connectionSocket.getOutputStream());
			clientSentence = inFromClient.readLine();
			System.out.println("from client: "+clientSentence);
			capitalizedSentence = clientSentence.toUpperCase() + '\n';
			outToClient.writeBytes(capitalizedSentence);
		}

	}
}
